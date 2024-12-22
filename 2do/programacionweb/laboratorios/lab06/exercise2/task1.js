let stroka = 'aba aca aea abba adca abea'

document.getElementById("stroka").innerHTML = stroka

function task1(){

let words = stroka.split(" ")
let answer = ""


for(let i = 0; i< words.length ; i++){

    if(words[i].length == 4){
        if(words[i].charAt(0) == "a" && words[i].charAt(3) =="a" ){
            answer = answer + " " + words[i]
        }
    }
    

}

document.getElementById("answer").innerHTML = `task 1 : ${answer}`



}