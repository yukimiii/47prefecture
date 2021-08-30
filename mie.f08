program mie
  implicit none
  character :: str*3
  integer :: m,i,e
  do m=32,127
   str(1:1)=char(m)
   do i=32,127
    str(2:2)=char(i)
    do e=32,127
     str(3:3)=char(e)
     if(trim(str) == "MIE") then
      print *, str
     else if (str(1:3) == "TSU") then
      print *, " "//char(90)
     end if
    end do
   end do
  end do
end program mie
