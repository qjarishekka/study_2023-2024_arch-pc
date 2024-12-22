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

let stroka2 = '23 2+3 2++3 2+++3 445 677'

document.getElementById("stroka2").innerHTML = stroka2

function task2(){

    let words = stroka2.split(" ")
    let answer = ""


    for(let i = 0 ; i < words.length ; i++){

       

        if(words[i].charAt(0) == "2" && words[i].charAt(words[i].length-1) == "3"  ){

            answer = answer + ' ' + words[i]

         }
    }

    document.getElementById("answer2").innerHTML = `task 2 : ${answer}`

}

// example : asda asd fda asdfasdf fddfdf aqwa aewqweqwa askslma akmslopa ahia aisdfsa aghia 

function task3(){

    let array = ""
    array = document.getElementById("textOfTask3").value

    let words = array.split(" ")
    let answer3 = ""

    for(let i = 0; i< words.length ; i++){
        console.log(words[i])

        if(words[i].charAt(0) == "a" && words[i].charAt(words[i].length-1) == "a" ){

            if(isThereAProhibitedConsonant(words[i])){
                answer3 = answer3 +" " + words[i]
            }
            



        }


    }

    document.getElementById("answer3").innerHTML = answer3

}

function isThereAProhibitedConsonant(w){

    let word = ""
    word = w

    for(let i = 0 ; i < word.length ; i++){
        if(word.charAt(i) == "g" || word.charAt(i) == "h" || word.charAt(i) == "i" ){
            return false
        }
    }

    return true

}

