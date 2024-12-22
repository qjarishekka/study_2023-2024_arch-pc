{
    let array = [];
    //array.push("X");
    //document.write(array)
    
    
    
    function anotherX(){
        array.push("X");
        //document.write(array);
        //alert("el codigo se ejecuto")
        document.getElementById("first").innerHTML=`task 1 : ${array}`;
    }
    
    
}

function extratequivalent(){

    let val = document.getElementsByTagName("td")
    let days = document.getElementById("days")
    let selecValue = days.value
    

    
    
    for(let i = 0 ; i < 7 ; i++){
    
        let text = val[i*2].textContent
    
    
        if( text.includes(selecValue) ){
            document.getElementById('answer').innerHTML = `task 2 : ${val[i*2 + 1].innerHTML}`
        }
    
    
    }
    
    }

    let numeros = [10,-1,4,2,-9,5,12,-6,-10,-15]
document.getElementById("numeros").innerHTML = numeros


function task3(){

    numeros.sort( (itemA , itemB)=>{
        return itemA - itemB
    })


    numeros.reverse()
    
    //console.log(numeros)
    document.getElementById("numeros").innerHTML = `task 3 : ${numeros}` 

}

let words = ["alpha" , "charlie" , "parangaricutirimicuaro" , "hello" , "ey" , "money" , "get" , "forward" ]

document.getElementById("words").innerHTML = words

function task4(){

words.sort((a, b)=>{
    return a.length - b.length

})

words.reverse()

document.getElementById("words").innerHTML = `task 4: ${words}` 

}