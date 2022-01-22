from django.db import models
from datetime import datetime

# Create your models here.
class dht111(models.Model):
    temperature = models.CharField(max_length=122)
    humidity = models.CharField(max_length=122)
    time = models.TimeField()
    date = models.DateField()
    

    