#!/usr/bin/python3
""" the main hbnb console """
import cmd
from models import *
import os

class HBNBCommand(cmd.Cmd):
    """ define the hbnb command interpreter """
    prompt = "(hbnb) "
    validCls = ["BaseModel", "User", "State",\
                "City", "Place", "Review", "Amenity"]

    def do_quit(self, arg):
        """ exit the command line """
        return True

    def do_EOF(self, arg):
        """ exit the command line with ctrl+d signal """
        print("")
        return True

    def emtpyline(self):
        """ handle an empty line prints nothing """
        pass
    
if __name__ == "__main__":
    HBNBCommand().cmdloop()
