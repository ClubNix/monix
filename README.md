# Monix

Account manager system

## Django 
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

## Lua Dependencies
- [löve](https://love2d.org/)
- [luajit](http://luajit.org/)
- [lzmq](https://github.com/zeromq/lzmq)
	* [luarocks](https://luarocks.org/)
- [mongodb](https://www.mongodb.org/)
