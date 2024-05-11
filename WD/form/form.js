document.querySelector('form').addEventListener('submit', function(e){
    e.preventDefault();
    console.log("Readying....");
    const name = document.getElementById("name").value;
    const gender = document.querySelector('input[name="gender"]:checked').value;
    const eye = document.getElementById("eye").value;
    const chec = document.querySelectorAll('input[name="chec"]:checked');
    const ability = document.getElementById("ability").value;

    const thingsChecked = [];
    chec.forEach(function(chec) {
        thingsChecked.push(chec.value);
    });


    if (name.length < 3) {
        alert('Name cannot be less than 3 letters');
        return; 
    }


    console.log('Name:', name);
    console.log('Gender:', gender);
    console.log('Eye Color:', eye);
    console.log('Things:', thingsChecked);
    console.log('Ability: ', ability)
    console.log('submitted');
    document.querySelector('#msg').innerHTML = "Form Submitted";
});

