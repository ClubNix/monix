from django.http import HttpResponseRedirect
from django.shortcuts import get_object_or_404, render
from django.urls import reverse
from django.views import generic
from django.utils import timezone

from .models import Member

class IndexView(generic.ListView):
    model = Member
    template_name = 'monix/index.html'
    context_object_name = 'user_list'
    def get_queryset(self):
        return Member.objects.order_by('pseudo')[:]


def check_int(s):
    if s[0] in ('-', '+'):
        return s[1:].isdigit()
    return s.isdigit()

def change(request, sign):
    member = get_object_or_404(Member, pk=request.POST['id']) 
    number = request.POST['num']
    if number == '': # If the string is empty, put 1 into the string
        number = '1'
    if check_int(number): # Check if the string is an int
        member.baton += int(number) * sign
        member.last_move = timezone.now()
        member.save()
        f= open("logs.txt","a")
        f.write(str(member.last_move.strftime("%Y-%m-%d %H:%M:%S")) 
            + " " 
            + str(member.pseudo) 
            + " : " 
            + str(int(number) * sign) 
            + " donc total de " 
            + str(member.baton) 
            + "\n")
        f.close()
        # Always return an HttpResponseRedirect after successfully dealing
        # with POST data. This prevents data from being posted twice if a
        # user hits the Back button.
        return HttpResponseRedirect(reverse('monix:index'))
    else: # Ask to give an int
        return render(request, reverse('monix:index'), {
            'error_message': "Please type an integer.",
        })

def remove(request):
    return change(request, -1)

def add(request):
    return change(request, 1)

