# Inbyggda-system
ATmega328p with TRITECH board

1. open project in cmd or wsl(if wsl skip step 2)
2. run wsl
3. run "sudo mkdir /run/screen" since directory is not found for some reason...
4. run "sudo apt-get --reinstall install screen" since i always get error "must have mode 777."
5. flash using arduino ide
6. flash using command "make"
7. enter screen using "screen /dev/ttyS3 38400"

