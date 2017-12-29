# **Robot "Hacking"**

[source of default robot SSH info] http://doc.aldebaran.com/2-1/dev/tools/opennao.html
*open terminal 
* enter nao@chapman.local
* when prompted type yes
* when a password is requested type nao
* when in the robot type nano
* paste in the following text, removing the <> and text inside and replace it
_from naoqi import ALProxy_
_tts = ALProxy("ALTextToSpeech", "localhost", 9559)_
_tts.say("<enter what you want the robot to say>")_
* press ctrl+O
*save the file as any name you want with the extension .py at the end
* press enter
* press ctrl+X
* type python <filename>.py changing <filename> to the name of file you just made
* once entered the robot should say what you entered into the <> of the file
