# My Journal/Lab Book

**ls** lsts all files and directories in a folder that are not hidden

**cd** changes to specified directory from the one you are in

**mkdir** makes a directory from the folder you are in

**echo** writes the following quoted text into the specified file

**cat** concatcates files and print to standard output. (links files together into single files)

**cp** copies files and directories

**mv** moves files to different directories or renames them

**rm** removes specified files or directories

**rm -rf** recursively removes all folders without stops (dangerous with rm -rf/ especially when ran in sudo as it recusrivley removes home folder)

**sudo apt-get install** install the package to which you are refering

**cowsay** the greatest program in all of linux

**top** displays the processes in linux  
---

## **the _git_ breakdown**

### **to send a file to github:**
* get git, terminal the following:  sudo apt-get install git
* go to [GitHub] (https://github.com)
* make an account
*navigate (using terminal) to the directory where the file you want to send to GitHub is
* type git init
* type git config user.name "username"
* type git config user.email "email"
* type git add "file name you want to send to github"
* type git commit
* nano will open
* type in a breif description of what you have done
* press ctrl+O
* press enter
* press ctrl+X
* to see recent commits type git log
* go to github 
* make a new repository by pressing the arrow in the top corner 
* name it what you want, "don't check initialize this respository with a README"
* return to terminal
* navigate to the directory with the commits in it 
* type git remote add origin https://github.com/<youraccount>/<repository>.git (changing the 
<boxed in> words with the relevant info.)
* to send your file to git type git push -u origin

**to retreive a file from github**
* if on a new device repeat steps until configuring your username
* type git remote add origin https://github.com/<youraccount>/<repository>.git (changing the 
<boxed in> words with the relevant info.)
* type git pull origin master
* type ls to confirm that the file is still there
* when done save, and type git commit
* enter description
* type git push -u origin

---

## **Robot "Hacking"**

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

---

## **DC Motor build**

### **Design Notes**
*Note 1:* based off the notes from the previous lecture we are going to go ahead with the double coiled design. this should allow for the motor to move without starting momentum and opperate at slower speeds.
*Note 2* Our first motor design was pretty terrible. The nails weren't aligned and the holders werent parallel, resulting in a armature that wouldn't spin. There were only 60 coils resulting in a solenoid with low resistance and little strength, meaning the coil would get hot easily and spin weakly. Finally, the commutator was wrinkled and pitted making it very hard for the brushes to make contact with the armature without stopping it by digging in. We are going to take these notes into account and remake the motor differently.
*Note 3* Taking into account our observations from Note 2 we have built a new motor. It has four coils of 100 windings. it uses a screw with ball bearings to allow for more slip and smoother motion. We are printing a stand so that the parts all fit together as well as possible. we have taken steps to make the commutator as smooth as possible. the bushes will be stiff wires attatched to the base.
*Note 4* the new motor designs have a few issues that make it unsusable. The bearings have a abec rating of 5 wich means it has quite a lot of friction. while the motor moves it can't really spin. so we are going to look for some better bearings. 
*Note 5* the new bearings (taken from a fidget spinner) work. Using brushes made from a thick copper wire, and the commutator, detailed below, the motor is self-starting and appears to spin rather quickly. The coils do not get hot. One small note, due to the slightly rough contacts due to solder being used to remove the coating on the brushes, when the motor spins at high speed there can be some sparks coming off the commutator, but they do not appear to be dangerous. 
### **Build**


cork with commutator and windings:
![cork with commutator and windings] (Journal/Journal_Photos/Commutator.jpg)

Number of Coils:60

Resistance of 2 ohms: 
![resistance Reading from Multimeter] (Journal/Journal_Photos/resistance.jpg)

2 Coiled design:

Final design:  

Final Design theoretical calculations:

---

### **Encoder**

the encoder disk followed a fairly budget, yet effective option, simply it is a small cardboard disk, cut from a pizza box, with a hole in the center the size of the motor shaft, and a notch in it. For the electronic side of the encoder we followed the schematics provided. Although it didn't nessisarily cause a problem I thought it was weird that the cathode and anode for the phototranistor were opposite length of the LED, but other than that it was pretty straight forward. We drilled a hole into the mount to fit the en coder.

### **Photos**


--- 
##**Arm Project**

###Servo control

**Arduino Control**
code 1:

*Notes* this works ok, but not perfectly. according to the servo datasheet, there are 3 extremes, -90, 0, and 90. the pulse width required for the 0 position is 1.5 ms, -90 is 1ms and 90 is 2ms. 2ms for pwm is 255 or 100% duty cycle. 1.5ms is 75% of the duty cycle or 191 pwm. Finally, 1 ms is 50% duty cyle or 127.

code 2:
Taking into consideration the notes from the previous code I will try to improve the servo.

*Notes* 255 does not work for pwm as it is just a high signal. Although 127 should be the minimum value, trial and error shows 50 is the lowest signal that can be registered. As the pwm signal is expected to be 20 ms by the motor it might be worth it to try to making my own form of pwm with the digtial signals and delays.

