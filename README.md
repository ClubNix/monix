# Monix

Account manager system

## Deploy Django
### Docker-compose
Install docker-compose on your computer [here](https://docs.docker.com/compose/install/).
Download git repository.
If you have a custom css file, add it to your currrent folder.
Launch it with `docker-compose up`

#### Create admin user
If you need admin access (export/import data), please create an admin user.
```
docker-compose exec monix bash
python manage.py createsuperuser
```

## Dev Django 
### Dependencies
Read requierements.txt

### Install in virtualenv
```bash
virtualenv my_django
source ./my_django/bin/activate
cd monix/djangoapp
pip3 install -r requirements.txt
```

### Deploy
```bash
python3 manage.py migrate
python3 manage.py createsuperuser
python3 manage.py runserver
```
