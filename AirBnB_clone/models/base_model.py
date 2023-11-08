#!/usr/bin/python3
import models
import datetime
import uuid

class BaseModel:
    
    def __init__(self, *args, **kwargs):
        self.updated_at = datetime.datetime.now()
        self.id = str(uuid.uuid4())
        self.created_at = datetime.datetime.now()
        if len(kwargs) == 0:
            models.storage.new(self)


    def __str__(self):
        new = (f"[{self.__class__.__name__}] ({self.id}) {self.__dict__}")
        return new
       
    def save(self):
        self.updated_at = datetime.datetime.now()
        models.storage.save() 

    def to_dict(self):
        self.__dict__.update({'__class__': self.__class__.__name__})
        for key in self.__dict__:
            if key == 'updated_at' or key == 'created_at':
                self.__dict__[key] = datetime.datetime.now().isoformat()
        return self.__dict__
