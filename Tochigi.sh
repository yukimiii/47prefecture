T='Tochigi';echo $(echo $T|tr $T 0-6;echo '+299995')|bc|tr 0-6 $T
