#!/usr/bin/python3
""" the main hbnb console """
import cmd
from models import *

class HBNBCommand(cmd.Cmd):
    """ define the hbnb command interpreter """
    prompt = "(hbnb) "
    validCls = ["BaseModel, "User", "State",
                "City", "Place", "Review", Amenity"]

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
    def do_creat(self, args):
        args = arg.split()

        if len(args) == 0:
            print("** class name missing **")
        else:
            if len(args) > 0 and args[0] in HBNBCommand.validCls:
                newObject = eval(args[0])()
                print(newObject.id)
                newObject.save()
            else:
                return
        

if __name__ == "__main__":
    HBNBCommand().cmdloop()
