let countrys = {
    Минск: 'Беларусь',
    Москва:'Россия',
    Киев:'Украина' ,
}



function task1(){

    let answer = ""

    for(prop in countrys){
        
        answer += `<p> ${countrys[prop]} : столица ${prop} </p>`
    }

    document.getElementById("answer1").innerHTML = answer
}