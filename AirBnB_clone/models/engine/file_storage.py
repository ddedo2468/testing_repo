#!/usr/bin/python3
""" define the file storage class """

import json
from models.base_model import BaseModel
from models.review import Review
from models.state import State
from models.place import Place
from models.city import City
from models.user import User
from models.amenity import Amenity

class FileStorage:
    """ the file storage main class """
    __file_path = ""
    __objects = dict

    def all(self):
        """ returns a dictionary """
        return self.__objects
    
    def new(self):
        """ set an obj in __objects """
        keydict = "{}.{}".format(obj.__class__.__name__,
                obj.id)
        self.__objects[keydict] = obj

