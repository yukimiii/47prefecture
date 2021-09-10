// converts an image file into another format.
// So far following image formats are supported: [jpeg, png, gif]
package main

import (
	"flag"
	"fmt"
	"image"
	"image/gif"
	"image/jpeg"
	"image/png"
	"io"
	"os"
	"path/filepath"
)

type CLI struct {
	In       io.Reader
	Out, Err io.Writer
	V        bool
}

type Converter struct {
	in, out string
}

var Supported = map[string]bool{
	"jpg": true, "jpeg": true, "png": true, "gif": true, "tiff": false, "bmp": false,
}

func main() {
	c := &CLI{In: os.Stdin, Out: os.Stdout, Err: os.Stderr, V: false}
	f_in := flag.String("i", "png", "file format to convert from")
	f_out := flag.String("o", "gif", "file format to convert to")
	flag.BoolVar(&c.V, "v", false, "show debug messages")
	flag.Parse()
	if c.V {
		fmt.Fprintln(c.Out, "in=", *f_in, ", out=", *f_out, flag.Args())
	}
	n, err := ConvertAll(*f_in, *f_out, flag.Args(), c)
	if err != nil {
		fmt.Fprintln(c.Err, err)
		os.Exit(1)
	}
	fmt.Fprintln(c.Out, n, "files converted")
}

func ConvertAll(in, out string, dirs []string, c *CLI) (n int, err error) {
	if err := IsValidExt(in); err != nil {
		return 0, err
	}
	if err := IsValidExt(out); err != nil {
		return 0, err
	}
	if len(dirs) == 0 {
		return 0, fmt.Errorf("invalid argument: missing target dir")
	}
	for _, d := range dirs {
		if info, err := os.Stat(d); err != nil {
			return 0, fmt.Errorf("error: " + d + ": no such file or directory")
		} else if !info.IsDir() && filepath.Ext(d) != "."+in {
			return 0, fmt.Errorf("error: " + d + ": not a directory or a valid file")
		} else if c.V {
			fmt.Fprintln(c.Out, info.Name())
		}
	}
	n = 0
	for _, d := range dirs {
		err = filepath.Walk(d,
			func(p string, info os.FileInfo, err error) error {
				if err != nil {
					fmt.Fprintln(c.Err, p, err)
					return nil
				}
				if info.IsDir() || filepath.Ext(p) != "."+in {
					return nil
				}
				if err := Convert(p, in, out); err != nil {
					fmt.Fprintln(c.Err, p, err)
					return nil
				}
				if c.V {
					fmt.Fprintln(c.Out, p, "\t=>\n", ConvertExt(p, out))
				}
				n += 1
				return nil
			})
		if err != nil {
			return n, err
		}
	}
	return
}

// Convert converts format of given file
func Convert(fn string, in, out string) error {
	if err := IsValidExt(in); err != nil {
		return err
	}
	if err := IsValidExt(out); err != nil {
		return err
	}
	if ext := filepath.Ext(fn); ext != "."+in {
		return fmt.Errorf("invalid argument: unmatched extensions %s and %s", ext, in)
	}
	img, err := readImg(fn, in)
	if err != nil {
		return err
	}
	err = writeImg(img, ConvertExt(fn, out), out)
	if err != nil {
		return err
	}
	return nil
}

func readImg(fn, ext string) (img image.Image, err error) {
	fin, err := os.Open(fn)
	if err != nil {
		return
	}
	defer fin.Close()
	switch ext {
	case "jpg", "jpeg":
		img, err = jpeg.Decode(fin)
	case "png":
		img, err = png.Decode(fin)
	case "gif":
		img, err = gif.Decode(fin)
	default:
		return nil, fmt.Errorf("invalid argument: unsupported extension %s", ext)
	}
	return
}

func writeImg(img image.Image, fn, ext string) (err error) {
	fout, err := os.Create(fn)
	if err != nil {
		return
	}
	defer func() {
		if cerr := fout.Close(); cerr != nil {
			err = cerr
		}
	}()
	switch ext {
	case "jpg", "jpeg":
		err = jpeg.Encode(fout, img, nil)
	case "png":
		err = png.Encode(fout, img)
	case "gif":
		err = gif.Encode(fout, img, nil)
	default:
		return fmt.Errorf("invalid argument: unsupported extension %s", ext)
	}
	return
}

// IsValidExt checks if the ext is supported
func IsValidExt(ext string) error {
	v, ok := Supported[ext]
	switch {
	case ok && v:
		return nil
	default:
		return fmt.Errorf("invalid argument: unsupported extension %s", ext)
	}
	return nil
}

// ConvertExt returns the new filename after conversion
func ConvertExt(fn, out string) string {
	return fn[:len(fn)-len(filepath.Ext(fn))] + "." + out
}

