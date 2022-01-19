from django.shortcuts import render, HttpResponse
from data.models import dht111

# Create your views here.
def fetch(request):
    task = dht111.objects.latest('id')
    context = {'task':task}
    # return render(request,'fetch.html',tasks)
    return render(request,'fetch.html',context)
    # return HttpResponse("Now Fetching the data from MySQL")

