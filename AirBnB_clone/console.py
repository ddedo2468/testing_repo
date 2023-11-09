#!/usr/bin/python3
""" the main hbnb console """
import cmd
from models import *
from models.engine.file_storage import FileStorage
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
    
    def do_create(self, arg):
        """"""
        args = arg.split()
        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.validCls:
            print("** class doesn't exist **")
        else:
            obj = BaseModel()
            obj.save()
            print(obj.id)
    
    def do_show(self, arg):
        """"""
        args = arg.split()
        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.validCls:
            print("** class doesn't exist **")
        elif len(args) == 1:
            print("** instance id missing **")
        elif args[1] not in FileStorage.__objects:
            print("** no instance found **")
        else:
            obj = FileStorage.__objects.get(args[0], args[1])
            print(obj)

if __name__ == "__main__":
    HBNBCommand().cmdloop()
