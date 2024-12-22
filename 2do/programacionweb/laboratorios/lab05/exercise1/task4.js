let words = ["alpha" , "charlie" , "parangaricutirimicuaro" , "hello" , "ey" , "money" , "get" , "forward" ]

document.getElementById("words").innerHTML = words

function task4(){

words.sort((a, b)=>{
    return a.length - b.length

})

words.reverse()

document.getElementById("words").innerHTML = `task 4: ${words}` 

}