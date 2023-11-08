#!/usr/bin/python3
""" define the file storage class """

import json
import os
import models
from models.base_model import BaseModel
from models.review import Review
from models.state import State
from models.place import Place
from models.city import City
from models.user import User
from models.amenity import Amenity

class FileStorage:
    """ the file storage main class """
    __file_path = "file.json"
    __objects = {}

    def all(self):
        """ returns a dictionary """
        return FileStorage.__objects
    
    def new(self, obj):
        """ set an obj in __objects """
        dictkey = "{}.{}".format(obj.__class__.__name__, obj.id)
        FileStorage.__objects[dictkey] = obj
    
    def save(self):
        """ serialize __objects to json file """
        serialized = {}
        for dictkey, obj in FileStorage.__objects.items():
            serialized[dictkey] = obj.to_dict()
        with open(FileStorage.__file_path, 'w') as file:
            json.dump(serialized, file)

    def reload(self):
        """ deserialize json file to __objects """
        if os.path.exists(FileStorage.__file_path):
            with open(FileStorage.__file_path, 'r') as file:
                try:
                    serialized = json.load(file)
                    for dictkey, obj_dict in serialized.items():
                        class_name = obj_dict.pop("__class__", None)
                        if class_name:
                            obj_id = dictkey.split('.')[1]
                            cls = getattr(models, class_name)
                            obj = cls(**obj_dict)
                            FileStorage.__objects[dictkey] = obj
                except FileNotFoundError:
                    pass
