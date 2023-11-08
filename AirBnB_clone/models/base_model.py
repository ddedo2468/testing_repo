#!/usr/bin/python3
import datetime
import uuid

class BaseModel:
    
    def __init__(self, updated_at=datetime.datetime.now(), id=str(uuid.uuid4()), created_at=datetime.datetime.now(), **kwargs):
        self.updated_at = updated_at
        self.id = id
        self.created_at = created_at
        kwargs.update(self.__dict__)

    def __str__(self):
        new = (f"[{self.__class__.__name__}] ({self.id}) {self.__dict__}")
        return new
       
    def save(self):
        self.updated_at = datetime.datetime.now()
        return self.updated_at 

    def to_dict(self):
        self.__dict__.update({'__class__': self.__class__.__name__})
        for key, value in self.__dict__.items():
            if isinstance(value, type(datetime)):
                self.__dict__[key] = datetime.datetime.isoformat(value)        
        return self.__dict__
