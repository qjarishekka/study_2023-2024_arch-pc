function task2(){

    let numberWeek =  document.getElementById("numberWeek").value -1
    numberWeek+2

    document.getElementById("answerTask2").innerHTML = `task 2: ${getDayOfTheWeek(numberWeek)}` 

}

function getDayOfTheWeek(n){

    let DaysOfTheWeek = ["понедельник", "вторник" , "среда" , "четверг" , "пятница" , "суббота" , "воскресенье" ]

    if(n == -1){
        return "понедельник"
    }

    return DaysOfTheWeek[n]

}