dlghash
=======

An alternative hash algorithm with a variable output length


**Building**

To build and install use:  
`$ make && sudo make install`


**Running the tool**

Hashing a string:  
`echo 'test' | ./dlghash`  
`dlghash 'test'`


Hashing a string with a specific length:  
`dlghash 'test' 256`


Hashing a file:  
`dlghash < file`
