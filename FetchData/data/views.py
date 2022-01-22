import json
from django.shortcuts import render, HttpResponse
from data.models import dht111

# Create your views here.
def fetch(request):
    # -----this is fetching from the database and also get the latest id from database and show the template page.

    temperature = []
    humidity = []
    time = []
    task = dht111.objects.latest('id')
    all_data = dht111.objects.all().order_by('-id')[:24]
    for i in all_data:
        temperature.append(i.temperature)
        humidity.append(i.humidity)
        time.append(i.time)
  

    

    
    context = {'task':task,'temperature': json.dumps(temperature[::-1]),'humidity':json.dumps(humidity[::-1]),'time1': time[-1] ,'time2': time[-2] ,'time3': time[-3] ,'time4': time[-4] ,'time5': time[-5] , 'time6': time[-6],'time7': time[-7],'time8': time[-8],'time9': time[-9],'time10': time[-10],'time11': time[-11],'time12': time[-12],'time13': time[-13],'time14': time[-14],'time15': time[-15],'time16': time[-16],'time17': time[-17],'time18': time[-18],'time19': time[-19],'time20': time[-20],'time21': time[-21],'time22': time[-22],'time23': time[-23],'time24': time[-24] }
    return render(request,'fetch.html',context)

