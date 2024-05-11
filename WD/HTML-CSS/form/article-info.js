document.querySelector('form').addEventListener('submit', function(e){
    e.preventDefault();
    const name = document.getElementById("name").value;
    const Booktype = document.getElementById("Booktype").value;
    const subject = document.getElementById("subject").value;
    const file = document.getElementById("filepath").value;

    if (name.length < 3) {
        alert('Name cannot be less than 3 letters');
        return; 
    }
    console.log('Name:', name);
    console.log('Booktype:', Booktype);
    console.log('Subject:', subject);
    console.log('File:', file);
    console.log('submitted');
    document.querySelector('#msg').innerHTML = "Form Submitted";
});

document.querySelector('form').addEventListener('reset', function(e){
    e.preventDefault();
    document.getElementById("name").value = '';    
    document.getElementById("filepath").value = '';   
    document.getElementById("Booktype").value = '';   
    document.getElementById("subject").value = '';   

    console.log('reset');
    document.querySelector('#msg').innerHTML = "Form Reset";
});

