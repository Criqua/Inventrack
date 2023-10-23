#pragma once
#include "SystemString_toStdString.h"
#include "productos/archivarProductos.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Alertas
	/// </summary>
	public ref class Alertas : public System::Windows::Forms::Form
	{
	public:
		Alertas(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Alertas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox
			// 
			this->richTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox->Location = System::Drawing::Point(12, 0);
			this->richTextBox->Name = L"richTextBox";
			this->richTextBox->ReadOnly = true;
			this->richTextBox->Size = System::Drawing::Size(677, 412);
			this->richTextBox->TabIndex = 0;
			this->richTextBox->Text = L"";
			// 
			// Alertas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(701, 412);
			this->Controls->Add(this->richTextBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Alertas";
			this->Text = L"Alertas";
			this->Load += gcnew System::EventHandler(this, &Alertas::Alertas_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Alertas_Load(System::Object^ sender, System::EventArgs^ e) {
		int total = 0;
		/* Recorremos todo el archivo de registro de productos en búsqueda de productos con información
		...urgente por medio de estas funciones, además de mostrarlos en el ícono de mail*/
		archivoProducto::notificarAlertas(total, false);
		archivoProducto::mostrarAlertas(richTextBox);
	}
	};
}
