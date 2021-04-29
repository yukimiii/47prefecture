T='Tochigi';echo $(echo $T|tr $T 0-6;echo '+300000-5')|bc|tr 0-6 $T
