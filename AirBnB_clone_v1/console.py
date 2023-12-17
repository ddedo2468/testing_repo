#!/usr/bin/python3
""" the main hbnb console """
import cmd
import os
from models import storage
from models.base_model import BaseModel
from models.user import User
from models.state import State
from models.city import City
from models.place import Place
from models.amenity import Amenity
from models.review import Review


class HBNBCommand(cmd.Cmd):
    """ define the hbnb command interpreter """
    prompt = "(hbnb) "
    validCls = ["BaseModel", "User", "State",
                "City", "Place", "Review", "Amenity"]

    def do_quit(self, arg):
        """ exit the command line """
        return True

    def do_EOF(self, arg):
        """ exit the command line with ctrl+d signal """
        print("")
        return True

    def emptyline(self):
        """ handle an empty line prints nothing """
        pass

    def do_create(self, arg):
        """  Creates a new instance of a given class. The class' ID is printed and the instance is saved to the file file.json.  """
        args = arg.split()
        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.validCls:
            print("** class doesn't exist **")
        else:
            obj = eval(args[0])()
            obj.save()
            print(obj.id)

    def do_show(self, arg):
        """ shows all information about a class  """
        args = arg.split()
        all_obj = storage.all()

        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.validCls:
            print("** class doesn't exist **")
        elif len(args) == 1:
            print("** instance id missing **")
        else:
            obj = "{}.{}".format(args[0], args[1])
            if obj not in all_obj:
                print("** no instance found **")
            else:
                print(all_obj[obj])

    def do_destroy(self, arg):
        """ Deletes an instance of a given class with a given ID.  """
        args = arg.split()
        all_obj = storage.all()

        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.validCls:
            print("** class doesn't exist **")
        elif len(args) == 1:
            print("** instance id missing **")
        else:
            obj = "{}.{}".format(args[0], args[1])
            if obj not in all_obj:
                print("** no instance found **")
            else:
                del all_obj[obj]
                storage.save()

    def do_all(self, arg):
        """ Prints all string representation of all instances of a given class.  """
        class_name = arg.split()[0] if arg else None
        obj_list = []

        if class_name and class_name not in HBNBCommand.validCls:
            print("** class doesn't exist **")
        else:
            for obj in storage.all().values():
                if not class_name or class_name == obj.__class__.__name__:
                    obj_list.append(str(obj))

            print(obj_list)

    def do_update(self, arg):
        """ Updates an instance based on the class name, id, and kwargs passed.  """
        args = arg.split()
        if len(args) == 0:
            print("** class name missing **")
            return
        class_name = args[0]
        if class_name not in HBNBCommand.validCls:
            print("** class doesn't exist **")
            return

        if len(args) < 2:
            print("** instance id missing **")
            return
        instance_id = args[1]
        objdict = storage.all()
        instance_key = "{}.{}".format(class_name, instance_id)

        if instance_key not in objdict:
            print("** no instance found **")
            return

        if len(args) < 3:
            print("** attribute name missing **")
            return
        attribute_name = args[2]

        if len(args) < 4:
            print("** value missing **")
            return
        attribute_value = args[3]
        obj = objdict[instance_key]
        if hasattr(obj, attribute_name):
            setattr(obj, attribute_name, attribute_value)
            obj.save()
        else:
            setattr(obj, attribute_name, attribute_value)
            obj.save()


if __name__ == "__main__":
    HBNBCommand().cmdloop()
