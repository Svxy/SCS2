function copyToClipboard() {
    const commandText = document.getElementById('command-text').innerText;
    navigator.clipboard.writeText(commandText).then(function() {
        const copyButton = document.getElementById('copy-btn');
        const clipboardIcon = document.getElementById('clipboard-icon');
        const checkmarkIcon = document.getElementById('checkmark-icon');
        
        clipboardIcon.style.display = 'none';
        checkmarkIcon.style.display = 'block';
        copyButton.classList.add('copied');
        
        setTimeout(() => {
            clipboardIcon.style.display = 'block';
            checkmarkIcon.style.display = 'none';
            copyButton.classList.remove('copied');
        }, 2000);
    }, function(err) {
        console.error('Could not copy text: ', err);
    });
}