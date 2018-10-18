from django.urls import path

from . import views


app_name = 'monix'
urlpatterns = [
    # ex: /monix/
    path('', views.IndexView.as_view(), name='index'),
    path('remove/', views.remove, name='remove'),
    path('add/', views.add, name='add'),
]

