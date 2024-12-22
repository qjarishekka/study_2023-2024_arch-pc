function task1(){
 
    let button = document.getElementById("answer1").innerText = "no"
    console.log(button)
}

let answer = ""

function task2(){

    

    let enteringText = document.getElementById("enteringWord").value

    answer += " " +enteringText

    document.getElementById("enteringWord").value = ""

    document.getElementById("answer2").innerText = `task 2 : ${answer}`


}

function enter(e){
    if(e.keyCode == 13){
        task2()
    }
}