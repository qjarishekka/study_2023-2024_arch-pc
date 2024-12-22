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

let obj = {a: 1, b: 2, c: 3};

function task2(){
    document.getElementById("answer2").innerHTML = ` <p> ${obj["c"]}</p>  <p> ${obj.c}</p>  `
}