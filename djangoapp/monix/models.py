import datetime


from django.db import models
from django.utils import timezone


class Member(models.Model):
    pseudo = models.CharField(max_length=200)
    last_move = models.DateTimeField('Dernier mouvement sur le compte')
    baton = models.IntegerField(default=0)
    def __str__(self):
        return self.pseudo
        
class History(models.Model):
    message = models.CharField(max_length=200, null=True)
    style = models.CharField(max_length=200, null=True)
