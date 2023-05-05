* Update: Remove String Obfuscation folder, and added a loop that continuously tries to fetch the shellcode until successful.
* note: CSE.cpp output gets detected under Wacatac.H!ml, remove the loop function or just use the control flow obfuscation version to get through it.
# ShellStream

Windows-based application downloads a binary file from a server using WinHTTP and executes it by copying it to memory and invoking it with a function pointer. This should only be intended for ethical purposes.

 - Downloads a binary file from a remote server using HTTP protocol and WinHTTP library.
 - Executes the downloaded binary by copying it to memory and invoking it with a function pointer.
 - Control Flow Obfuscation
 - String Obfuscation (not working as of updating this)

__I don't condone using this tool for any kind of malicious activity__

(if the project doesn't compile, you can edit the compiler and add any missing directories.)


# Results:

__NORMAL:__

![yeah no1](https://user-images.githubusercontent.com/107830842/235260521-fd756a29-96e7-4434-8a56-5fe44a1311cc.JPG)




__CONTROL FLOW OBFUSCATION:__

![1of26 (2)](https://user-images.githubusercontent.com/107830842/235336808-274db6cb-24fa-400d-9da6-f7a153d9f5ef.JPG)




Other notes:
CFO = Control Flow Obfuscation




 # To Do
 - [ ] Interactable python script
 - [ ] Process Injection
 - [ ] Dll compiler
 - [x] Loop until successful fetch of shellcode
