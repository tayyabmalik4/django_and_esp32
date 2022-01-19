from re import sub
from django.shortcuts import render, HttpResponse
from blog.models import submitdata

# Create your views here.
def submitdataa(request):
    if request.method=="POST":
        name = request.POST.get('name')
        lastname=request.POST.get('lastname')
        submit = submitdata(name=name,lastname=lastname)
        submit.save()
        print(submit)
    return render(request, 'submitdata.html')

def fetchdata(request):
    task = submitdata.objects.all()
    content = {'tasks':task}
    return render(request, 'fetchdata.html', content)
