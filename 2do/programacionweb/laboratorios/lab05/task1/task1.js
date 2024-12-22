let array = [];
//array.push("X");
//document.write(array)

function anotherX(){
    array.push("X");
    //document.write(array);
    //alert("el codigo se ejecuto")
    document.getElementById("first").innerHTML=array;
}


function extratequivalent(){

let val = document.getElementsByTagName("td")

let days = document.getElementById("days")

let selecValue = days.value



for(let i = 0 ; i < 7 ; i++){

    let text = val[i*2].textContent


    if( text.includes(selecValue) ){
        document.getElementById('answer').innerHTML = val[i*2 + 1].innerHTML
    }


}

//console.log("se ejecuta" ,selecValue, val)

//document.getElementById("answer").innerHTML = val[1].innerHTML
//document.getElementById("answer").innerHTML = val

}
