function toggleMode() {
  const html = document.documentElement
  html.classList.toggle("light")

  //Pegar a imagem
  const img = document.querySelector("#mdprofile img")

  //Substituir a Imagem
  if (html.classList.contains("light")) {
    img.setAttribute("src", "./assets/avatar.png")
    // Se tiver Light Mode, adicionar imagem Dark
    img.setAttribute("alt", "Imagem modo light")
  } else {
    img.setAttribute("src", "./assets/avatar-light.png")
    // Se tiver Dark Mode, adicionar Imagem light
    img.setAttribute("alt", "Imagem modo Dark")
  }
}
