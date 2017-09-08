#!python 
import platform
import os
import sys
import glob
from build_support import *
from build_config import *

print("Scons Script Build!")
projectmode = ARGUMENTS.get('mode', 'debug')   #holds current mode
projecttool = 'window'

#check if the user has been naughty: only 'debug' or 'release' allowed
if not (projectmode in ['debug','release']):
	print("Error: expected 'debug' or 'release', found: " + projectmode)

#tell the user what we're doing
print('**** Compiling in ' + projectmode + ' mode...')

#--------
# Main application folder dir and output folder
#--------

buildroot = './bin/' + projectmode + '/'			#holds the root of the build directory tree
targetpath = buildroot + '/' + projectname	#holds the path to the executable in the build directory
#-------

if projecttool == 'window': #window tool default to vs2017
	#http://scons.org/doc/0.97/HTML/scons-man.html
	#need to lanuch vcvars32.bat script so it can be add to os.environ else it will display 'cl' is not recognized as an internal or external command
	#this will deal with the Visual Studio 
	env = Environment(ENV = os.environ) #this load user complete external environment
else:
	#default current tool from os
	env = Environment(ENV = os.environ) #this load user complete external environment
	#pass

system = platform.system()

#--------
# Operating System Checks and Tools
#--------
if system=='Windows':
	print("**** Window Tool")
	# Something to do with link error
	#https://msdn.microsoft.com/en-us/library/y0zzbyt4.aspx
	env.Append(LINKFLAGS=['/SUBSYSTEM:CONSOLE'])
	#env.Append(CPPDEFINES = ['SFML_STATIC']) 
	#env.Append(CPPFLAGS=['-DOPENGL_ENABLED'])
	#env.Append(CPPFLAGS=['-DGLES2_ENABLED'])
	#env.Append(CCFLAGS='-MD -MF -DDEFINE1')
	#env.Append(CCFLAGS=['-MD -MF'])
	#env.Append(CCFLAGS = '-rdynamic')
	#env.Append(LINKFLAGS=['/NODEFAULTLIB:library'])
	
	
	env.Append(CPPPATH=include_packages) #include files
	#build lib file
	#--imgui
	env.Library(buildroot + '\\imgui',Glob(IMGUI_PATH + '\\*.cpp')) #Imgui
	#--SFML
	#env.Library(buildroot + 'sfml' , lib_files,CCFLAGS='-MD -MF')
	#env.Library(buildroot + 'sfml' , lib_files)

	#env.Library(buildroot + 'sfml-graphics' , SFML_LIBS + '\\sfml-graphics.lib')
	#env.Library(buildroot + 'sfml-system.' , SFML_LIBS + '\\sfml-system.lib')
	#env.Library(buildroot + 'sfml-window' , SFML_LIBS + '\\sfml-window.lib')

	#env.Library(buildroot + 'sfml' , lib_files)

	env.Library(buildroot + 'sfml' , Glob(SFML_LIBS +"\\*.lib"))

	#copy file or folder to bin dir
	#http://scons.org/doc/1.2.0/HTML/scons-user/c2848.html
	for basename in dll_packages:
		env.Install(buildroot,SFML_BIN + basename + ".dll") #copy dll to output
	#env.Install(buildroot,Glob("SFML-2.4.2\\bin\\*.dll") #copy dll to output
	#print("buildroot:",buildroot)
	#application
	#env.Program(targetpath, Glob(builddir + '\\*.cpp'), LIBS=lib_packages, LIBPATH=['.','SFML-2.4.2\\lib', buildroot])
	env.Program(targetpath, Glob(builddir + '\\*.cpp'), LIBS=lib_packages, LIBPATH=['.',SFML_LIBS, buildroot])
print("**** Scons Script End!")
