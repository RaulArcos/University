from django.shortcuts import redirect, render
from django.views.generic import TemplateView
import os

class SignUpView(TemplateView):
    template_name = 'registration/signup.html'


def home(request):
    if request.user.is_authenticated:
        if request.user.is_teacher:
            return redirect('teachers:quiz_change_list')
        else:
            return redirect('students:quiz_list')

    try:
        hostname = os.environ['HOSTNAME']
    except:
        hostname = 'host'

    return render(request, 'classroom/home.html', {
        'hostname': hostname
    })
