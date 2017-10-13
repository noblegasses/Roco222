#My Journal/Lab Book

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
### **Build**


cork with commutator and windings:
![cork with commutator and windings] (Journal_Photos/Commutator.jpg)

Number of Coils:60

Resistance of 2 ohms:
![resistance Reading from Multimeter] (Journal_Photos/resistance.jpg)




