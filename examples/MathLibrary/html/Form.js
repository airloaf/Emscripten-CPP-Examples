function press(){
    var val = document.getElementById("number").value;
    var answerObj = document.getElementById("answer");
    
    if(val == "" || val < 0){
        answerObj.innerText = "Input a positive integer!"
        return ;
    }

    answer = Module.ccall("fact", null, ['number'], [val]);

    answerObj.innerText = val + "! = " + answer;
}