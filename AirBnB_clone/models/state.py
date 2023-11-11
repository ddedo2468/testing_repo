#!/usr/bin/python3
""" creating a state class from the base model """

from models.base_model import BaseModel


class State(BaseModel):
    """ defines a State class """
    name = ""
