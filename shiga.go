package main

import (
	"fmt"
	"strings"
)

type lake struct {
	name        string
	area        float64
	perimeter   float64
	depth       float64
	volume      float64
	description []string
}

func (l lake) String() string {
	return fmt.Sprintf("Lake %s\narea: %fkm^2 perimeter: %fkm depth: %fm volume: %fkm^3\n%v\n", l.name, l.area, l.perimeter, l.depth, l.volume, strings.Join(l.description, ", "))
}
func main() {
	biwako := lake{name: "Biwako", area: 669.26, perimeter: 235.20, depth: 103.58, volume: 27.5, description: []string{"freshwater", "tectonic", "largest in Japan"}}
	fmt.Print(biwako)
}
