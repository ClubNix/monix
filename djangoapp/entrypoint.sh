#!/bin/bash


# Exit immediately if a command exits with a non-zero status.
# http://stackoverflow.com/questions/19622198/what-does-set-e-mean-in-a-bash-script
set -e # http://www.informatix.fr/tutoriels/unix-linux-bsd/bash-sortir-automatiquement-du-script-si-une-commande-echoue-182

# migrate
python manage.py migrate --noinput

#creat empty file to test if this script already ran
touch firsttime


#test if first time
if [-e firsttime]
then
echo "static files already collected"
else
echo "collecting static files"
# export static files
#python manage.py collectstatic --noinput

fi
python manage.py collectstatic --noinput


set +e 
#create superuser https://stackoverflow.com/questions/6244382/how-to-automate-createsuperuser-on-django
echo "create admin..."
script="
login = '$ADMIN_LOGIN';
password = '$ADMIN_PASS';
email = '$ADMIN_MAIL';

from django.contrib.auth.models import User;
if User.objects.filter(username=login).count()==0:
    from django.contrib.auth import get_user_model;
    User = get_user_model();
    User.objects.create_superuser(login, email, password)
    print('Superuser ' + login +' created')
else:
    print('Superuser creation skipped.')"

printf "$script" | python manage.py shell


set -e 
# run server
python manage.py runserver 0.0.0.0:8000


    #command: gunicorn mysite.wsgi