#!/usr/bin/python3
""" the engine heart """

from models.engine.file_storage import FileStorage

storage = FileStorage()
storage.reload()
