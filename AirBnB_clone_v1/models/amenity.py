#!/usr/bin/python3
""" creating an amenity class from the base model """

from models.base_model import BaseModel


class Amenity(BaseModel):
    """ Define the Amenity class """
    name = ""
