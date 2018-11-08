# Monix

Short whiteboard for Club*Nix.

## Deploy app
1. Install docker-compose on your computer [here](https://docs.docker.com/compose/install/).
- Download the `docker-compose.yml` file.
- If you have a custom css file, add it to your currrent folder.
- Edit the docker-compose.yml file.
- Launch it with `docker-compose up`

## Dev Django

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
