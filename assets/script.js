const card = document.querySelector(".card");
const sections = document.querySelectorAll(".card .body .list");
const buttons = document.querySelectorAll(".card .buttons button");
const popup = document.querySelectorAll("[data-popup]");
const popup_close = document.querySelectorAll(".popup-close");

const ButtonClick = e => {
  const targetSection = e.target.getAttribute("data-section");
  const section = document.querySelector(targetSection);
  targetSection !== "#about" ? card.classList.add("active") : card.classList.remove("active");
  card.setAttribute("data-state", targetSection);
  sections.forEach(s => s.classList.remove("active"));
  buttons.forEach(b => b.classList.remove("active"));
  e.target.classList.add("active");
  section.classList.add("active");
};

const PopupClick = e => {
  document.querySelectorAll(".popup-content.active").forEach(p => p.classList.remove("active"));
  setTimeout(() => {
    let b = document.querySelector(e.target.getAttribute("data-popup"));
    b ? b.classList.add("active") : document.querySelector("#none").classList.add("active");
  }, 1);
}
const CloseClick = e => e.target.closest(".popup-content").classList.remove("active");

buttons.forEach(btn => btn.addEventListener("click", ButtonClick));
popup.forEach(btn => btn.addEventListener("click", PopupClick));
popup_close.forEach(btn => btn.addEventListener("click", CloseClick));
