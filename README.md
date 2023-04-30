# ShellStream

Windows-based application downloads a binary file from a server using WinHTTP and executes it by copying it to memory and invoking it with a function pointer. This should only be intended for ethical purposes.

 - Downloads a binary file from a remote server using HTTP protocol and WinHTTP library.
 - Executes the downloaded binary by copying it to memory and invoking it with a function pointer.
 - Control Flow Obfuscation
 - String Obfuscation (not working as of updating this)

__I don't condone using this tool for any kind of malicious activity__

(if the project doesn't compile, you can edit the compiler and add any missing directories.)


# Results tested with Havoc shellcodes:

__NORMAL:__

![yeah no1](https://user-images.githubusercontent.com/107830842/235260521-fd756a29-96e7-4434-8a56-5fe44a1311cc.JPG)




__CONTROL FLOW OBFUSCATION:__

![1of26 (2)](https://user-images.githubusercontent.com/107830842/235336808-274db6cb-24fa-400d-9da6-f7a153d9f5ef.JPG)




Other notes:
SO = String Obfuscation
, CFO = Control Flow Obfuscation

