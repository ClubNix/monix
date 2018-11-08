# Pull base image
FROM python:3.7

# Set environment varibles
ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1

# Set work directory
WORKDIR /code

# Install dependencies
RUN pip install --upgrade pip
ADD ./djangoapp/requirements.txt /code/
RUN pip install -r requirements.txt  --no-cache-dir

# Copy project
ADD ./djangoapp /code/djangoapp
WORKDIR /code/djangoapp

# Launch website
EXPOSE 8000
CMD ["sh", "./entrypoint.sh"]