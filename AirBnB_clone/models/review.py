#!/usr/bin/python3
""" creating a review class from the base model """

from models.base_model import BaseModel


class Review(BaseModel):
    """ Define the review class """
    place_id = ""
    user_id = ""
    text = ""
