Title: ym2149-test

The ym2149-test is a little firmware to check that the [YM2149 &
Arduino circuit][2] is working properly.

Requirements
------------

The following libraries are required:

* gcc-avr (or avr-gcc depending on the distribution)
* avr-libc
* avrdude

How to test the circuit
-----------------------

    $ make
    $ make flash
	
Common errors
-------------

If getting the following error message when trying to flash the chip (`make flash`):

```
avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0xff
avrdude: stk500_recv(): programmer is not responding
```

Try to change the baudrate to 57600 in the Makefile (1st line).  Some
models may accept faster transfer rates than others.


More information
----------------

More information can be found on my blog:

* [Driving YM2149F sound chip with an Arduino][2]
* [Arduino Hello World without IDE][3]

Besides, a video showing the [YM2149 & Arduino circuit playing a tune][1] is
available.

[1]: https://www.youtube.com/watch?v=MTRJdDbY048
[2]: http://www.florentflament.com/blog/driving-ym2149f-sound-chip-with-an-arduino.html
[3]: http://www.florentflament.com/blog/arduino-hello-world-without-ide.html
