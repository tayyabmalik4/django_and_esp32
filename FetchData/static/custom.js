

//starting the temperature graph
const temp =()=>{
    var a = "{{temperature|safe}}";
    console.log("************************** " , a);
const ctx = document.getElementById('canvas-temp').getContext('2d');
const myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: ['Red', 'Blue', 'Yellow', 'Green', 'Purple', 'Orange'],
        datasets: [{
            label: 'Temperature',
            data:[12, 19, 3, 5, 2, 3],
            backgroundColor:'transparent',
            borderColor: 'red', 
            borderWidth: 4
        }]
    },
    options: {
        scales: {
            y: {
                beginAtZero: true
            }
        }
    }
});
} 

// starting the humidity graph
const humid = ()=>{
const ctx = document.getElementById('canvas-humid').getContext('2d');
const myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: ['Red', 'Blue', 'Yellow', 'Green', 'Purple', 'Orange'],
        datasets: [{
            label: 'Humidity',
            data: [12, 19, 3, 5, 2, 3],
            backgroundColor:'transparent',
            borderColor: 'green',
            borderWidth: 4
        }]
    },
    options: {
        scales: {
            y: {
                beginAtZero: true
            }
        }
    }
});
}
temp()
humid()