# ContinuousShellcodeExecutor

Just a small utility program that can download and execute shellcode from a remote server on a continuous basis. It uses WinHTTP to communicate with the remote server and retrieve the shellcode, and then XOR encryption to obfuscate the data. The program can be useful for various security testing and research purposes, such as testing the efficacy of antivirus software or exploring the potential of remote code execution vulnerabilities.


 - Download and execute shellcode
 - Retrieve shellcode using WinHTTP
 - Use XOR encryption to obfuscate data
 - Continuous execution of shellcode
 - Minimal obfuscation

__I don't condone using this tool for any kind of malicious activity__

(if the project doesn't compile, you can edit the compiler and add any missing directories.)



Results with the normal one:
![yeah no1](https://user-images.githubusercontent.com/107830842/235260521-fd756a29-96e7-4434-8a56-5fe44a1311cc.JPG)

Results with control flow obfuscation:
![1of26](https://user-images.githubusercontent.com/107830842/235336742-1f38d41d-27ae-4bf5-8446-66baeec656b2.png)


Other notes:
SO = String Obfuscation
, CFO = Control Flow Obfuscation

String Obfuscation as of writing this doesn't work.

