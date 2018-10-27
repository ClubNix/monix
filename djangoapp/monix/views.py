from django.http import HttpResponseRedirect
from django.shortcuts import get_object_or_404, render
from django.urls import reverse
from django.views import generic
from django.utils import timezone
from datetime import datetime

from .models import Member
from .models import History

class IndexView(generic.ListView):
    model = Member
    template_name = 'monix/index.html'
    context_object_name = 'user_list'
    def get_queryset(self):
        return Member.objects.order_by('pseudo')[:]
    def get_context_data(self, **kwargs):
        # Call the base implementation first to get a context
        context = super().get_context_data(**kwargs)
        # Add in a QuerySet of all the books
        context['time'] = datetime.now()
        if History.objects.exists():
            context['last_history'] = {
            'message' : History.objects.last().message,
            'style' : History.objects.last().style,
            }
            History.objects.last().delete()
        return context


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
        History.objects.get_or_create( #get if user uses back button
            message = (
                str(int(number) * sign)
                + " pour l'user "
                + str(member.pseudo)
                + str(member.last_move.strftime(" à %H:%M:%S."))
            ),
            style = "good"
        )
    else: # Ask to give an int
        History.objects.get_or_create( #get if user uses back button
            message = "Please give an int", style = "error"
        )
    # Always return an HttpResponseRedirect after successfully dealing
    # with POST data. This prevents data from being posted twice if a
    # user hits the Back button.
    return HttpResponseRedirect(reverse('monix:index'))
    
def remove(request):
    return change(request, -1)

def add(request):
    return change(request, 1)

